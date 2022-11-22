/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    strs.sort();
    //console.log(strs);
    let firstIndex=0;
    let lastIndex = 0;
    let ans="";
    //console.log(strs[0][firstIndex]);
    while(firstIndex<strs[0].length && lastIndex<strs[strs.length-1].length && strs[0][firstIndex]===strs[strs.length-1][lastIndex]){
        ans = ans+strs[0][firstIndex];
        firstIndex++;
        lastIndex++;
    }
    return ans;
};