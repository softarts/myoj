/*
Given an array of strings names of size n. You will create n folders in your file system such that, at the ith minute, you will create a folder with the name names[i].

Since two files cannot have the same name, if you enter a folder name that was previously used, the system will have a suffix addition to its name in the form of (k), where, k is the smallest positive integer such that the obtained name remains unique.

Return an array of strings of length n where ans[i] is the actual name the system will assign to the ith folder when you create it.

 

Example 1:

Input: names = ["pes","fifa","gta","pes(2019)"]
Output: ["pes","fifa","gta","pes(2019)"]
Explanation: Let's see how the file system creates folder names:
"pes" --> not assigned before, remains "pes"
"fifa" --> not assigned before, remains "fifa"
"gta" --> not assigned before, remains "gta"
"pes(2019)" --> not assigned before, remains "pes(2019)"
Example 2:

Input: names = ["gta","gta(1)","gta","avalon"]
Output: ["gta","gta(1)","gta(2)","avalon"]
Explanation: Let's see how the file system creates folder names:
"gta" --> not assigned before, remains "gta"
"gta(1)" --> not assigned before, remains "gta(1)"
"gta" --> the name is reserved, system adds (k), since "gta(1)" is also reserved, systems put k = 2. it becomes "gta(2)"
"avalon" --> not assigned before, remains "avalon"
Example 3:

Input: names = ["onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece"]
Output: ["onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece(4)"]
Explanation: When the last folder is created, the smallest positive valid k is 4, and it becomes "onepiece(4)".
 

Constraints:

1 <= names.length <= 5 * 104
1 <= names[i].length <= 20
names[i] consists of lowercase English letters, digits, and/or round brackets.

这道题看上去很简单，用hashmap
有些edge case，但是我都解决了，一次通过
 */

import java.util.*;

class Solution {
    public String[] getFolderNames(String[] names) {
        Map<String, Integer> map = new HashMap<>();
        String[] answer = new String[names.length];
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < names.length; i++ ) {
            String word = names[i];
            

            
            if (!map.containsKey(word) ) {
                answer[i] = word;
                map.put(word, 0);
            } else {
                
                int count = map.get(word);

                for (int j=count+1;;j++) {
                    sb.append(word).append('(').append(j).append(')');
                    if (!map.containsKey(sb.toString())) {
                        answer[i] = sb.toString();
                        map.put(word, j);        
                        map.put(answer[i],0);
                        sb.setLength(0); // 成功后记得清空 sb 供下一个元素使用
                        break;
                    }
                    sb.setLength(0);
                }
            }
        }
        return answer;
        
    }
}
