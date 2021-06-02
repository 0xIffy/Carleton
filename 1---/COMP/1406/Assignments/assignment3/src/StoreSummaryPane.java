import javafx.scene.layout.Pane;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

public class StoreSummaryPane extends Pane{
    TextField numSalesField, revField, $perField;

    public StoreSummaryPane(String title){
        Pane innerPane = new Pane();
        innerPane.setStyle("-fx-background-color: white; " + "-fx-border-color: gray; " + "-fx-padding: 4 4;");

        Label lab1 = new Label ("#Sales:");
        lab1.relocate(10,10);
        lab1.setPrefSize(70,30);
        Label lab2 = new Label ("Revenue:");
        lab2.relocate(10,40);
        lab1.setPrefSize(70,30);
        Label lab3 = new Label ("$ / Sale:");
        lab3.relocate(10,70);
        lab1.setPrefSize(70,30);

        numSalesField = new TextField();
        numSalesField.relocate(10,10);

    }
}
