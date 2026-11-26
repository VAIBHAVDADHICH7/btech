// Module 1: Swing Components & MVC Architecture
import javax.swing.*;
import java.awt.*;

public class Exp01_SwingMVCApp {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame f = new JFrame("RTU Swing MVC Demo");
            f.setLayout(new FlowLayout());
            JTextField nameField = new JTextField(12);
            JCheckBox agreeBox = new JCheckBox("Accept Terms");
            JRadioButton r1 = new JRadioButton("B.Tech", true);
            JRadioButton r2 = new JRadioButton("M.Tech");
            ButtonGroup bg = new ButtonGroup(); bg.add(r1); bg.add(r2);
            JButton btn = new JButton("Submit");
            JLabel status = new JLabel("Ready");

            btn.addActionListener(e -> status.setText(
                "Hello " + nameField.getText() + " | Agreed: " + agreeBox.isSelected()));

            f.add(nameField); f.add(agreeBox); f.add(r1); f.add(r2); f.add(btn); f.add(status);
            f.setSize(420, 150);
            f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            f.setVisible(true);
        });
    }
}
