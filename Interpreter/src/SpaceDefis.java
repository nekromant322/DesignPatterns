public class SpaceDefis extends Interpreter
{

    @Override
    public String interpret(String text)
    {

        String new_text = "";
        for(int i = 0 ; i < text.length() - 1; i++)
        {
            if(text.charAt(i) == '—' && text.charAt(i+1) != ' ')
            {
                new_text = new_text + "— ";
                continue;
            }
            new_text = new_text + text.charAt(i);
        }
        new_text = new_text +  text.charAt(text.length() - 1);
        return new_text;
    }
}
