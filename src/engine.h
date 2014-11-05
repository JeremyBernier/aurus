#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <unistd.h>
#include <math.h>
#include <getopt.h>
#include <string.h>

#include <jack/jack.h>
#include <jack/transport.h>

using namespace std;

const double PI = 3.14;

class Engine {
	private:
		int bpm;
		bool playing;
		unsigned long sr;
		jack_transport_state_t transport_state;
		jack_port_t *output_port;
		jack_nframes_t tone_length, wave_length;
		jack_default_audio_sample_t *wave;
		long offset;
		// int transport_aware;
		jack_client_t *client;

		void process_silence (jack_nframes_t nframes);
		void process_audio (jack_nframes_t nframes);
		static int staticProcessCallback (jack_nframes_t nframes, void *arg);
		void initJack();
		void usage();
		int processCallback (jack_nframes_t nframes, void *arg);
		int sample_rate_change();
		void buildWave();
	public:
		Engine();
		void setPlayMode(bool);
};