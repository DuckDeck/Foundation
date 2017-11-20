class Tree{
    constructor(value){
        this.value = value
        this.isTag = false
    }
    static initWithLeftTag(value,parent){
        let s = new Tree(value)
        s.setLeftChild(parent)
        s.isTag = true
    }
    setLeftChild(tree){
        this.leftChild = tree
    }
    setRightChild(tree){
        this.rightChild = tree
        this.isTag = false
    }
    getLeftChild(){
        return this.leftChild
    }
    getRightChild(){
        return this.rightChild
    }

    forwardTraverse(){
        if(this.value == null){
            return
        }
        if(this.isTag){
            return
        }
        console.log(this.value)
        if(this.getLeftChild() != null)
            this.getLeftChild().forwardTraverse()
        if(this.getRightChild() != null)
            this.getRightChild().forwardTraverse()
    }

    middleTraverse(){
        if(this.value == null){
            return
        }
        if(this.isTag){
            return
        }
        if(this.getLeftChild() != null)
            this.getLeftChild().middleTraverse()
        console.log(this.value)
        if(this.getRightChild() != null)
            this.getRightChild().middleTraverse()
    }

    backTraverse(){
        if(this.value == null){
            return
        }
        if(this.isTag){
            return
        }
        if(this.getLeftChild() != null)
            this.getLeftChild().backTraverse()
        if(this.getRightChild() != null)
            this.getRightChild().backTraverse()

        console.log(this.value)
    }

    brotherTraverse(){
        if(this.value == null){
            return
        }
        console.log(this.value)
        //这种数据结构形式很难实现兄弟遍历

    }

     
}
//这个真的是无解吗？
//null连不上对象，暂时无解
function createTreewithForward(tree,data,index){
    if(Object.prototype.toString.call(data) != '[object String]'){
        return null
    }
    if(index >= data.length){
        return null
    }
    if(data[index] == '#'){//问题是右边的树没法创建了
        tree = null
        ++index
    }
    else{
        tree = new Tree(data[index])
        ++ index
        index = createTreewithForward(tree.leftChild,data,index)
        index = createTreewithForward(tree.rightChild,data,index)
    }
    
    return index
}

let data = 'AB#D##C##'
let tree = new Tree(data[0])
let index = createTreewithForward(tree.leftChild,data,1)
createTreewithForward(tree.rightChild,data,index)
console.log(tree.forwardTraverse())

