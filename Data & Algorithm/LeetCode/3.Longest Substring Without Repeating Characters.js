//Given a string, find the length of the longest substring without repeating characters.

//Examples:

//Given "abcabcbb", the answer is "abc", which the length is 3.

//Given "bbbbb", the answer is "b", with the length of 1.

//Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

//给出一个字符串（String）,找到字符串中无重复的最长串长度


//输入"abcacbbb"，最长串是"abc",长度是3
//输入"bbbbb"，最长串是"b",长度是1
//输入"pwwkew"，最长串是"wke",长度是3

/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    if(s.length < 0){
        return 0
    }
    let tmp = []
    let i = 0
    let j = 0
    let k = []

    while(i < s.length ){
        if(tmp.indexOf(s[j])<0 && j < s.length){
            tmp.push(s[j])
            j++
        }
        else{
            i++
            j = i
            if(tmp.length > k.length){
                k = tmp
            }
            tmp = []
        }   
    }
    return k.length
};

//这种算法不够高效，还得再想想，因为有回溯所以是O[n^2]
// let result = lengthOfLongestSubstring(`abcdefghijklmnopqrstZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`)

// console.log(result)

var lengthOfLongestSubstring2 = function(s){
    if(s.length < 0){  //小于0 直接返回0
        return 0
    }
    let map = {}
    let max = 0
    for(let i = 0,j=0;i<s.length;i++){
        if(map[s[i]] != null){ //如果map里面有这个词了
            j = Math.max(j,map[s[i]] + 1)  //那么把j指向上一个词出现的位置的下一个，从这里开始累计
        }
        map[s[i]] = i  //把该词和index放到map里,如果存在这个词，就替换原来的位置
        max = Math.max(max,i-j+1) 
    }
    return max
}
//这个方法主要是回溯并不保存在循环里，而是保存在hash里，只保存上一次出现的位置，从上一次出现的位置开始循环
let result = lengthOfLongestSubstring2(`dvevafavffassesffgrew`)

console.log(result)