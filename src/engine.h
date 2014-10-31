#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>
#include <getopt.h>
#include <string.h>

#include <jack/jack.h>
#include <jack/transport.h>

class Engine {
	private:
		int freq;
		int bpm;
		unsigned long sr;
		jack_transport_state_t transport_state;
	public:
		Engine();
		void usage();
		void process_silence (jack_nframes_t nframes);
		// void process_audio (jack_nframes_t nframes);
		// int process (jack_nframes_t nframes, void *arg);
		int sample_rate_change ();
};