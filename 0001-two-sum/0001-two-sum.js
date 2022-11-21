/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let indices = {};
    for(let i=0; i<nums.length; i++){
        if(indices[target-nums[i]]!== undefined){
            return[indices[target-nums[i]],i];
        }
        indices[nums[i]]=i;
        // console.log(indices[nums[i]]);
    }
    return [];
};