#pragma once
#ifndef ListNode_H
struct ListNode {
	ListNode *next;
	int val;
	ListNode(int x) : val(x), next(NULL) {}
};
#endif