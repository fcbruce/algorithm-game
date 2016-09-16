/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function(lists) {
    function MinHeap(size) {
        this.size = 0;
        this.buffer = Array(size);
        
        this.insert = function (ListNode) {
            this.buffer[this.size] = ListNode;
            var pos = this.size++;
            while (pos !== 0) {
                var fa = (pos - 1) >> 1;
                if (this.buffer[pos].val < this.buffer[fa].val) {
                    [this.buffer[pos], this.buffer[fa]] = [this.buffer[fa], this.buffer[pos]];
                    pos = fa;
                } else {
                    break;
                }
            }
        };
        
        this.pop = function() {
            var min = this.buffer[0];
            var last = this.buffer[--this.size];
            var pos = 0;
            this.buffer[this.size] = null;
            this.buffer[0] = last;
            while (pos < this.size) {
                var lc = pos * 2 + 1, rc = lc + 1;
                if (lc >= this.size) break;
                if (rc >= this.size || this.buffer[lc].val < this.buffer[rc].val) {
                    if (this.buffer[lc].val < last.val) {
                        this.buffer[pos] = this.buffer[lc];
                        pos = lc;
                        this.buffer[pos] = last;
                    } else {
                        break;
                    }
                } else {
                    if (this.buffer[rc].val < last.val) {
                        this.buffer[pos] = this.buffer[rc];
                        pos = rc;
                        this.buffer[pos] = last;
                    } else {
                        break;
                    }
                }
            }
            return min;
        }
    }
    
    var heap = new MinHeap(lists.length);
    
    for (var i = 0; i < lists.length; i++) {
        if (lists[i] !== null) {
            heap.insert(lists[i]);
        }
    }
    var empty = function() {
        return heap.size === 0;
    }
    var head = null, tail = null;
    while (!empty()) {
        var node = heap.pop();
        if (node.next !== null) {
            heap.insert(node.next);
        }
        node.next = null;
        if (head === null) {
            head = tail = node;
        } else {
            tail.next = node;
            tail = node;
        }
    }
    return head;
};
