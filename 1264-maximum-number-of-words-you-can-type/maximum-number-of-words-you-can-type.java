class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        Set<Character> st = new HashSet<>();

        for(char ch : brokenLetters.toCharArray()){
            st.add(ch);
        }

        //split the text into words
        String[] words = text.split(" ");

        int count = 0;
        for(String word : words)
        {
             boolean cantype = true;

             //check each character
             for(char ch : word.toCharArray())
             {
                 if(st.contains(ch)){
                    cantype = false;
                    break;
                }
             }

             if(cantype){
                count++;

             }

        }
        return count;
       



    }
}