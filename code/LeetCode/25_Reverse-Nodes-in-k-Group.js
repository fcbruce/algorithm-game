/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var reverseKGroup = function(head, k) {
    var current = head;
    var last = null;
    while (current !== null) {
        var p = current;
        for (var i = 1; i < k; i++) {
            p = p.next;
            if (p === null) break;
        }
        if (p === null) break;
        p = p.next;
        var tail = null;
        for (var i = 0; i < k; i++) {
            var q = current.next;
            current.next = p;
            p = current;
            if (i === 0) {
                tail = p;
            }
            current = q;
        }
        if (last === null) {
            head = p;
        } else {
            last.next = p;
        }
        last = tail;
    }
    return head;
};
