public class RightQuots extends  Interpreter
{
    @Override
    public String interpret(String text)
    {

        String new_text = "";
        new_text = new_text + text.charAt(0);
        int count = 0;
        for(int i = 1 ; i < text.length(); i++)
        {
            if(text.charAt(i) == '«' )
            {
                if(count>0 && text.charAt(i-1) ==' ')
                {
                    new_text = new_text.substring(0,new_text.length()-1);
                    new_text = new_text + "»";
                    continue;
                }
               count++;
            }
            if(text.charAt(i) == '»')
            {

                count--;
            }
            new_text = new_text + text.charAt(i);
        }


        return new_text;
    }
}
