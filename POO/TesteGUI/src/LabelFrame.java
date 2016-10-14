import java.awt.FlowLayout;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import javax.swing.Icon;

public class LabelFrame extends JFrame {

	private JLabel label1;
	private JLabel label2;
	
	LabelFrame()
	{
		super( "Testing JLabel" );
		setLayout( new FlowLayout() );
		label1 = new JLabel("Label with text.");
		label1.setToolTipText("This is label1.");
		add(label1);
		
		label2 = new JLabel();
		label2.setText("Label with text at the bottom.");
		label2.setToolTipText("This is label2.");
		label2.setHorizontalTextPosition(SwingConstants.CENTER);
		label2.setVerticalTextPosition(SwingConstants.BOTTOM);
		add(label2);
		
	}
}
