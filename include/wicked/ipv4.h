/*
 * IPv4 device settings
 *
 * Copyright (C) 2012 Olaf Kirch <okir@suse.de>
 */

#ifndef __WICKED_IPv4_H__
#define __WICKED_IPv4_H__

#include <sys/socket.h>
#include <stdio.h>
#include <net/if.h>
#include <netinet/in.h>

#include <wicked/types.h>

struct ni_ipv4_devconf {
	ni_tristate_t		enabled;
	ni_tristate_t		forwarding;
	ni_tristate_t		arp_verify;
	ni_tristate_t		arp_notify;
	ni_tristate_t		accept_redirects;
};

struct ni_ipv4_devinfo {
	ni_ipv4_devconf_t	conf;
};

extern ni_ipv4_devinfo_t *	ni_netdev_get_ipv4(ni_netdev_t *);
extern void			ni_netdev_set_ipv4(ni_netdev_t *, ni_ipv4_devconf_t *);
extern ni_ipv4_devinfo_t *	ni_ipv4_devinfo_new(void);
extern void			ni_ipv4_devinfo_free(ni_ipv4_devinfo_t *);

extern int			ni_system_ipv4_devinfo_get(ni_netdev_t *, ni_ipv4_devinfo_t *);
extern int			ni_system_ipv4_devinfo_set(ni_netdev_t *, const ni_ipv4_devconf_t *);

#endif /* __WICKED_IPv4_H__ */

