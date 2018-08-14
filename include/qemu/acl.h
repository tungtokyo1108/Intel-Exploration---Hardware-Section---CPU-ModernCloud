/*
 * acl.h
 *
 *  Created on: Aug 14, 2018
 *      Author: tungdang
 */

#ifndef QEMU_ACL_H_
#define QEMU_ACL_H_

#include "qemu/queue.h"

typedef struct qemu_acl_entry qemu_acl_entry;
typedef struct qemu_acl qemu_acl;

struct qemu_acl_entry {
	char *match;
	int deny;
	QTAILQ_ENTRY(qemu_acl_entry) next;
};

struct qemu_acl {
	char *aclname;
	unsigned int nentries;
	QTAILQ_HEAD(,qemu_acl_entry) entries;
	int defaultDeny;
};

qemu_acl *qemu_acl_find(const char *aclname);

int qemu_acl_party_is_allowed(qemu_acl *acl, const char *party);
void qemu_acl_reset(qemu_acl *acl);
int qemu_acl_append(qemu_acl *acl, int deny, const char *match);
int qemu_acl_insert(qemu_acl *acl, int deny, const char *match, int index);
int qemu_acl_remove(qemu_acl *acl, const char *match);

#endif /* QEMU_ACL_H_ */
