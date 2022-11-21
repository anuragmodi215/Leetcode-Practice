/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if(x<0) return false;
    let newNumber = x;
    let temp=0;
    while(newNumber>0){
        let rem = newNumber%10;
        newNumber = parseInt(newNumber/10);
        temp = temp*10+rem;
        //console.log(newNumber);
    }
    // console.log(temp);
    if(temp==x) return true;
    else return false;
};