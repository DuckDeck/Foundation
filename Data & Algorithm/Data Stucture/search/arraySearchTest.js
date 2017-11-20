require('./array.extensions')
let t = [1,3,4,66,12,2,33,123,41]
console.log(t.sequentialSearch(4))
t.quickSort()
console.log(t)
console.log(t.fibonacciSearch(3)) //二分查找一定要用有顺序的数组
