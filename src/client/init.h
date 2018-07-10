#ifndef XDAG_MAIN_H
#define XDAG_MAIN_H

#include <time.h>
#include "block.h"
#include "system.h"

#define COINNAME "XDAG"

enum xdag_states
{
#define xdag_state(n,s) XDAG_STATE_##n ,
#include "state.h"
#undef xdag_state
};

extern struct xdag_stats
{
    xdag_diff_t difficulty, max_difficulty;
    uint64_t nblocks, total_nblocks;
    uint64_t nmain, total_nmain;
    uint32_t nhosts, total_nhosts, reserved1, reserved2;
} g_xdag_stats;

#define HASHRATE_LAST_MAX_TIME	(64 * 4) // numbers of main blocks in about 4H, to calculate the pool and network mean hashrate

extern struct xdag_ext_stats
{
	xdag_diff_t hashrate_total[HASHRATE_LAST_MAX_TIME];
	xdag_diff_t hashrate_ours[HASHRATE_LAST_MAX_TIME];
	xdag_time_t hashrate_last_time;
	uint64_t nnoref;
	uint64_t nhashes;
	double hashrate_s;
	uint32_t nwaitsync;
} g_xdag_extstats;

#ifdef __cplusplus
extern "C" {
#endif
	extern int xdag_init(int argc, char **argv, int isGui);

	extern int xdag_set_password_callback(int(*callback)(const char *prompt, char *buf, unsigned size));

#ifdef __cplusplus
};
#endif

#define xdag_amount2xdag(amount) ((unsigned)((amount) >> 32))
#define xdag_amount2cheato(amount) ((unsigned)(((uint64_t)(unsigned)(amount) * 1000000000) >> 32))

#endif
