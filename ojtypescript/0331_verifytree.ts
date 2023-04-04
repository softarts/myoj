function isValidSerialization(preorder: string): boolean {
    let deq: string[]= []
    var tokens = preorder.split(",")

    for (var item of tokens) {
        //console.log(tokens[item])
        //console.log(item)
        deq.push(item)
        while (deq.length>=3 && deq[deq.length-1]=="#" && deq[deq.length-2]=="#" && deq[deq.length-3]!="#") {
            deq.pop();deq.pop();deq.pop();
            deq.push("#")
        }
    }
    return deq.length==1 && deq[0]=="#"
};

// test here
let result = isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#")
console.log(result.toString())