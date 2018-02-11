
import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.GridLayout;

import javax.swing.*;

public class Window extends JFrame {
	
	private static final long serialVersionUID = 1L;
			
	Client client;
	JButton button1 = null;
	JButton button2 = null;
	JButton button3 = null;
	JTextArea textArea = null;
    JTextField textField;
	
	JPanel panel = new JPanel();
	
	JMenuBar menuBar = new JMenuBar();
	JMenu menu = new JMenu("menu");
	JToolBar toolBar = new JToolBar();
	
	
	public static void main(String argv[]){
		//System.setProperty("apple.laf.useScreenMenuBar", "true");
		Window client_multimedia = new Window();
	}
	
	public Window(){
		//client
		//client = new Client(Client.DEFAULT_HOST, Client.DEFAULT_PORT);
		try {
		      client = new Client(Client.DEFAULT_HOST, Client.DEFAULT_PORT);
		    } catch (java.io.IOException e) {
		      client = null;
		    }
		  
		
		//button initiation
		button1 = new JButton("search");
		button2 = new JButton("play");
		button3 = new JButton("exit");
		
		button1.addActionListener(new SearchListener());
		button2.addActionListener(new PlayListener());
		button3.addActionListener(new CloseListener());
		
		//textArea initiation
		textField = new JTextField();
		textArea = new JTextArea(30,30);
		textArea.setEditable(false);
		JScrollPane scrollPane = new JScrollPane(textArea);
		
		//set panel
		panel.setLayout(new GridLayout(1, 4));
		panel.add(textField);
		panel.add(button1);
		panel.add(button2);
		panel.add(button3);
	
		add(panel, BorderLayout.EAST);
		add(scrollPane,BorderLayout.CENTER);
		
		//set menuBar,toolBar
		JMenuItem menuItem1 = new JMenuItem("search");
		menuItem1.addActionListener(new SearchListener());
		menu.add(menuItem1);
		
		JMenuItem menuItem2 = new JMenuItem("play");
		menuItem2.addActionListener(new PlayListener());
		menu.add(menuItem2);
		
		JMenuItem menuItem3 = new JMenuItem("exit");
		menuItem3.addActionListener(new CloseListener());
		menu.add(menuItem3);
		
		toolBar.add(panel);// it will make panel below disappear
		menuBar.add(menu);
		setJMenuBar(menuBar);
		add(toolBar, BorderLayout.NORTH);
		
		
		
		//other
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("client-multimedia");
		pack();
		setVisible(true);
	}
	
	class SearchListener implements ActionListener{

	    public void actionPerformed(ActionEvent e) {
	        String text = textField.getText();

	        System.out.println("search: "+ text);
	        text = client.send("search "+ text);
	        text = text.replace(';', '\n') + '\n';
	        textArea.append(text);
	    }
	}
	
	class PlayListener implements ActionListener{
		public void actionPerformed(ActionEvent e) {
	        String text = textField.getText();

	        System.out.println("PLAY: "+ text);
	        text = client.send("play "+ text);
	        textArea.append(text);
	    }
	}
	
	class CloseListener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			System.exit(0);
		}	
	}
	

}
