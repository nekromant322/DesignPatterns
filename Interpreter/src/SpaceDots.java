public class SpaceDots extends Interpreter
{
    @Override
    public String interpret(String text)
    {
        String new_text = "";
        new_text = new_text +  text.charAt(0);
        for(int i = 1 ; i < text.length() - 1; i++)
        {
            if(text.charAt(i) == ' ' && (text.charAt(i+1) == '.' || text.charAt(i+1) == ',' ||text.charAt(i+1) == ')' ||text.charAt(i-1) == '(' || text.charAt(i+1) == '»'  || text.charAt(i-1) == '«') )
            {
                continue;
            }
            new_text = new_text + text.charAt(i);
        }
        new_text = new_text +  text.charAt(text.length() - 1);
        return new_text;
    }
}
