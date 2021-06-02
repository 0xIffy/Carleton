import javafx.application.Application;
import javafx.beans.Observable;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

public class DVDCollectionApp  extends Application {
    public void start(Stage primaryStage) {
        Pane  aPane = new Pane();

        // Create the labels
        Label lab1 = new Label("Title");
        Label lab2 = new Label("Year");
        Label lab3 = new Label("Length");

        // Create the lists
        String[]    titles = {"Star Wars", "Java is cool", "Mary Poppins", "The Green Mile"};
        String[]    years = {"1978", "2002", "1968", "1999"};
        String[]    lengths = {"124", "93", "126", "148"};
        // ... ADD CODE HERE ... //
        ListView<String> titList = new ListView<>();
        ListView<String> yearList = new ListView<>();
        ListView<String> lenList = new ListView<>();
//        ListView[] lists = new ListView[3];

        ObservableList<String> list1 = FXCollections.observableArrayList(titles);
        ObservableList<String> list2 = FXCollections.observableArrayList(years);
        ObservableList<String> list3 = FXCollections.observableArrayList(lengths);

        titList.setItems(list1);
        yearList.setItems(list2);
        lenList.setItems(list3);



        // Create the buttons
        // The following code shows how to set the font,
        // background color and text color of a button:
        // b.setStyle("-fx-font: 12 arial; -fx-base: rgb(0,100,0); " +
        //     "-fx-text-fill: rgb(255,255,255);");
        //the 3 rgb values represent the red/green/blue values for the color your want
        // ... ADD CODE HERE ... //

        // Don't forget to add the components to the window, set the title,
        // make it non-resizable, set Scene dimensions and then show the stage
        // ... ADD CODE HERE ... //
    }

    public static void main(String[] args) {
        launch(args);
    }
}
