/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    let mp = new Map();
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    let ans=mp[s[s.length-1]];
    //console.log(ans);
    for(let i=s.length-2; i>=0; i--){
        if(mp[s[i]]<mp[s[i+1]]){
            ans = ans-mp[s[i]];
        }
        else{
            ans = ans+mp[s[i]]
        }
    }
    return ans;
};