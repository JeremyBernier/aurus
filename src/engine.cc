#include "engine.h"

void Engine::process_silence (jack_nframes_t nframes) {
	jack_default_audio_sample_t *buffer = (jack_default_audio_sample_t *) jack_port_get_buffer (output_port, nframes);
	memset (buffer, 0, sizeof (jack_default_audio_sample_t) * nframes);
}

void Engine::process_audio (jack_nframes_t nframes) {
	jack_default_audio_sample_t *buffer = (jack_default_audio_sample_t *) jack_port_get_buffer (output_port, nframes);
	jack_nframes_t frames_left = nframes;
	
	while (wave_length - offset < frames_left) {
		memcpy (buffer + (nframes - frames_left), wave + offset, sizeof (jack_default_audio_sample_t) * (wave_length - offset));
		frames_left -= wave_length - offset;
		offset = 0;
	}
	if (frames_left > 0) {
		memcpy (buffer + (nframes - frames_left), wave + offset, sizeof (jack_default_audio_sample_t) * frames_left);
		offset += frames_left;
	}
}
int Engine::staticProcessCallback (jack_nframes_t _nframes, void *_udata) {
	// if (transport_aware) {
	// 	jack_position_t pos;

	// 	if (jack_transport_query (client, &pos) != JackTransportRolling) {
	// 		process_silence (nframes);
	// 		return 0;
	// 	}
	// 	offset = pos.frame % wave_length;
	// }
	return static_cast<Engine *>( _udata )->
					processCallback( _nframes, _udata );
}

int Engine::processCallback(jack_nframes_t _nframes, void * _udata) {

	if(playing) {
		process_audio(_nframes);
	}
	else {
		process_silence(_nframes);
	}
	// return 0;
	return 0;
}

Engine::Engine() {
	offset = 0;
	// transport_aware = 0;
	bpm = 140;
	playing = true;
	jack_status_t status;

	/* Initial Jack setup, get sample rate */
	if ((client = jack_client_open ("Aurus", JackNoStartServer, &status)) == 0) {
		fprintf (stderr, "jack server not running?\n");
    		// return 1;
	}
	jack_set_process_callback (client, staticProcessCallback, this);
	const char *portName = "metronome";
	output_port = jack_port_register (client, portName, JACK_DEFAULT_AUDIO_TYPE, 
		JackPortIsOutput | JackPortIsTerminal, 0);

	sr = jack_get_sample_rate (client);

	// const char *portNames[] = { "out_1", "out_2" };
	const char **outPorts = jack_get_ports(
                client,
                NULL,
                NULL,
                JackPortIsPhysical | JackPortIsInput);
	if(outPorts != NULL) {
		cout << outPorts[0] << endl;
		cout << outPorts[1] << endl;
		cout << jack_connect(client, portName, outPorts[0]);
		cout << jack_connect(client, portName, outPorts[1]);
		cout << "Should work" << endl;
	}
	else {
        cerr << "Warning, No outputs to autoconnect to" << endl;
	}
	buildWave();
}

void Engine::setPlayMode(bool mode) {
	playing = mode;
}


void Engine::buildWave() {
	int freq = 880;
	jack_default_audio_sample_t scale;
	int i, attack_length, decay_length;
	double *amp;
	double max_amp = 0.5;
	int attack_percent = 1, decay_percent = 10, dur_arg = 100;

	/* setup wave table parameters */
	wave_length = 60 * sr / bpm;
	tone_length = sr * dur_arg / 1000;
	attack_length = tone_length * attack_percent / 100;
	decay_length = tone_length * decay_percent / 100;
	scale = 2 * PI * freq / sr;

	fprintf (stderr, "sr = %lu\n",sr);
	fprintf (stderr, "wave_length = %d\n",wave_length);
	fprintf (stderr, "tone_length = %d\n",tone_length);
	fprintf (stderr, "sizeof = %lu\n",sizeof (jack_default_audio_sample_t));

	if (tone_length >= wave_length) {
		fprintf (stderr, "invalid duration (tone length = %" PRIu32
			", wave length = %" PRIu32 "\n", tone_length,
			wave_length);
    		// return -1;
	}
	if (attack_length + decay_length > (int)tone_length) {
		fprintf (stderr, "invalid attack/decay\n");
    		// return -1;
	}

	// /* Build the wave table */
	wave = (jack_default_audio_sample_t *) malloc (wave_length * sizeof(jack_default_audio_sample_t));
	amp = (double *) malloc (tone_length * sizeof(double));

	for (i = 0; i < attack_length; i++) {
		amp[i] = max_amp * i / ((double) attack_length);
	}
	for (i = attack_length; i < (int)tone_length - decay_length; i++) {
		amp[i] = max_amp;
	}
	for (i = (int)tone_length - decay_length; i < (int)tone_length; i++) {
		amp[i] = - max_amp * (i - (double) tone_length) / ((double) decay_length);
	}
	for (i = 0; i < (int)tone_length; i++) {
		wave[i] = amp[i] * sin (scale * i);
	}
	for (i = tone_length; i < (int)wave_length; i++) {
		wave[i] = 0;
	}

	if (jack_activate (client)) {
		fprintf (stderr, "cannot activate client");
    		// return 1;
	}
}

void Engine::usage() {
	// fprintf (stderr, "\n"
	// 	"usage: jack_metro \n"
	// 	"              [ --frequency OR -f frequency (in Hz) ]\n"
	// 	"              [ --amplitude OR -A maximum amplitude (between 0 and 1) ]\n"
	// 	"              [ --duration OR -D duration (in ms) ]\n"
	// 	"              [ --attack OR -a attack (in percent of duration) ]\n"
	// 	"              [ --decay OR -d decay (in percent of duration) ]\n"
	// 	"              [ --name OR -n jack name for metronome client ]\n"
	// 	"              [ --transport OR -t transport aware ]\n"
	// 	"              --bpm OR -b beats per minute\n"
	// 	);
}

int Engine::sample_rate_change () {
	// printf("Sample rate has changed! Exiting...\n");
	// exit(-1);
}