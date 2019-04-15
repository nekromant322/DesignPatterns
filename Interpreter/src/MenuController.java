import javafx.application.Platform;
import javafx.concurrent.Task;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.text.TextFlow;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;
import java.util.concurrent.TimeUnit;

import static java.lang.Thread.sleep;

public class MenuController
{



    @FXML
    public TextArea textArea;
    private String text;


    @FXML
    public void Edit(ActionEvent event) throws InterruptedException
    {
        text = textArea.getText();

        Tabs E1 = new Tabs();
        text = E1.interpret(text);
        Spaces E2 = new Spaces();
        text = E2.interpret(text);
        Quots E3 = new Quots();
        text = E3.interpret(text);
        Enters E4 = new Enters();
        text = E4.interpret(text);
        SpaceDots E5 = new SpaceDots();
        text = E5.interpret(text);
        Defis E6 = new Defis();
        text = E6.interpret(text);
        textArea.setText(text);


    }
}
