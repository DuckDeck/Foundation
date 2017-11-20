//https://leetcode.com/problems/add-two-numbers/
//You are given two non-empty linked lists representing two non-negative integers.
//The digits are stored in reverse order and each of their nodes contain a single digit.
// Add the two numbers and return it as a linked list.

//You may assume the two numbers do not contain any leading zero, except the number 0 itself.

//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8



// Definition for singly-linked list.
function ListNode(val) {
      this.val = val;
      this.next = null;
}
 
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let t1 = new ListNode((l1.val + l2.val) % 10)
    let t2 = t1
    let a = parseInt((l1.val + l2.val) / 10)
    while(l1.next != null || l2.next != null || a != 0){
          if(l1.next == null){
                l1.next = new ListNode(0)
          }
          if(l2.next == null){
                l2.next = new ListNode(0)
          }
          l1 = l1.next
          l2 = l2.next
          t1.next = new ListNode((l1.val + l2.val + a) % 10)
          a = parseInt((l1.val + l2.val + a) / 10)
          t1 = t1.next
    }
    return t2
};

//用链表的方式不好表达
//还是换成数组吧



let x = new ListNode(1)
let y = new ListNode(9)
y.next = new ListNode(9)

let z = addTwoNumbers(x,y)
console.log(z)

var addTwoNumbers2 = function(l1,l2){
      let a = 0
      let i = 0
      let t1 = []
      while(l1[i] != null || l2[i] != null || a != 0){
            let x = l1[i] || 0
            let y = l2[i] || 0
            t1[i] = (x + y + a) % 10
            a =  parseInt((x + y + a) / 10)
            i++
      }
      return t1
}

// let a = [2,4,3]
// let b = [5,6,4]
// let res = addTwoNumbers2(a,b)
// console.log(res)