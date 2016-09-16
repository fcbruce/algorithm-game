/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function(head) {
    var p = head;
    var prev = null;
    while (p !== null) {
        var q = p.next;
        if (q === null) break;
        var after = q.next;
        if (p === head) {
            head = q;
            q.next = p;
            p.next = after;
            prev = p;
        } else {
            prev.next = q;
            q.next = p;
            p.next = after
            prev = p;
        }
        p = after;
    }
    return head;
};
