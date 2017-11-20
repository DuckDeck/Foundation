//获取fibonacci
function fibonacci(n){
    if(!Number.isInteger(n)){
        throw Error('n must be num')
    }
    if(n <= 1){
        return n == 0 ? 0 : 1
    }
    return fibonacci(n-1) + fibonacci(n-2)
}
//获取fibonacci数组
function fibonacciNums(n){
    if(!Number.isInteger(n)){
        throw Error('n must be num')
    }
    let tmp = [0]
    if(n <= 0){
        return tmp
    }
    tmp = [0,1]
    let i = 2
    while(i < n){
        tmp.push(tmp[i-2] + tmp[i-1])
        i++
    }
    return tmp
}


// index start with 0
console.log(fibonacciNums(20))