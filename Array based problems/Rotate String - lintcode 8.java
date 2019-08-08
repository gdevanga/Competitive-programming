/*
Please see problem description @
http://www.lintcode.com/en/problem/rotate-string/
*/
public class Solution {
    /**
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
    public void rotateString(char[] str, int offset) {
        if (str.length == 0)
            return;
        if (str.length <= offset)
            offset = offset % str.length;
        while (offset > 0)
        {
            char  a = str[str.length-1];
            for (int i = str.length-2; i > -1; --i)
            {
                str[i+1] = str[i];
            }
            str[0] = a;
            --offset;
        }
    }
}