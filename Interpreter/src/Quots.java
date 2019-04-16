public class Quots extends  Interpreter
{
    @Override
    public String interpret(String text)
    {

        String new_text = "";
        for(int i = 0 ; i < text.length(); i++)
        {
            if(text.charAt(i) == '“' )
            {
                new_text = new_text + '«';
                continue;
            }
            if(text.charAt(i) == '”' )
            {
                new_text = new_text + '»';
                continue;
            }
            new_text = new_text + text.charAt(i);
        }


        return new_text;
    }
}
