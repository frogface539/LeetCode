/**
 * @param {string} val
 * @return {Object}
 */
var expect =(val)=> {
    return{
       toBe:(Value)=>{
        if(val===Value)
        {
            return true;
        }
        else
            throw new Error("Not Equal");
        
       },
       notToBe:(Value)=>{
        if(val !== Value){
            return true;
        }
        else
         throw new Error("Equal");
       }
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */