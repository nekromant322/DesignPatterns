public class Quots extends  Interpreter
{
    @Override
    public String interpret(String text)
    {
        text.replace('“', '«');
        text.replace('”', '»');
        return text;
    }
}
