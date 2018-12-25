
#include <errno.h>
#include <poll.h>

#include <bits/ensure.h>
#include <mlibc/debug.hpp>
#include <mlibc/sysdeps.hpp>

int poll(struct pollfd *fds, nfds_t count, int timeout) {
	int num_events;
	if(int e = mlibc::sys_poll(fds, count, timeout, &num_events); e) {
		errno = e;
		return -1;
	}
	return num_events;
}

