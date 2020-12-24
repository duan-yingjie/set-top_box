
import java.io.*;
import java.net.*;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.JButton;
import javax.swing.JTextArea;
import javax.swing.JToolBar;
import javax.swing.border.EmptyBorder;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JOptionPane;

public class Client
{
  private static final long serialVersionUID = 1L;
  static final String DEFAULT_HOST = "localhost";
  static final int DEFAULT_PORT = 3331;
  private Socket sock;
  private BufferedReader input;
  private BufferedWriter output;
  static inf224java frame = new inf224java();
  //---------------------------------------------------------java
  /*
   * part of java swing
   */
  public static class inf224java extends JFrame{
		JButton button1;
		JButton button2;
		JButton button3;
		JButton button4;
		JTextArea jta;	
		boolean send = false;
		String instruction=null;
		private static final long serialVersionUID = 1L;
		public inf224java()
		{
			setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			this.setSize(1000,500);
		
			JPanel contentPane = new JPanel();
			JPanel jp = new JPanel();
		
			contentPane.setLayout(new BorderLayout());
			setContentPane(contentPane);
			
			jta = new JTextArea(7,30);        //set the textarea
			jta.setLineWrap(true);   
			jta.setFont(new Font("Arial",Font.BOLD,16));   
	        jta.setBackground(Color.YELLOW);    
	        JScrollPane jsp=new JScrollPane(jta);   
	        Dimension size=jta.getPreferredSize();   
	        jsp.setBounds(110,90,size.width,size.height);
			contentPane.add(jsp,BorderLayout.CENTER);
			
			
			// create action 
			class buttonaction1 extends AbstractAction
			{
				public buttonaction1(String name) 
				{
					putValue(Action.NAME,name);
				}
				public void actionPerformed(ActionEvent e)
				{
					if(instruction==null) {
					
						instruction = "1 ";
						String name = JOptionPane.showInputDialog("please enter name");
					    instruction = instruction+name;
					    send = true;
					}
					
					else {
						jta.append("Instrution error\n");
						instruction = null;
					
					}
				}
			}
			
			class buttonaction2 extends AbstractAction
			{
				public buttonaction2(String name) 
				{
					putValue(Action.NAME,name);
				}
				public void actionPerformed(ActionEvent e) 
				{
					if(instruction==null) {
						instruction = "2 ";
						String name = JOptionPane.showInputDialog("Please enter the name:");
					    instruction = instruction+name;
					    send = true;
					}
					else {
						jta.append("Instrution error\n");
						instruction = null;
					
					}
					
				}
			}
			
			class buttonaction4 extends AbstractAction
			{
				public buttonaction4(String name) 
				{
					putValue(Action.NAME,name);
				}
				public void actionPerformed(ActionEvent e) 
				{
					if(instruction==null) {
						instruction = "3 ";
						String name = JOptionPane.showInputDialog("Please enter the name:");
					    instruction = instruction+name;
					    send = true;
					}
					else {
						jta.append("Instrution error\n");
						instruction = null;
					
					}
					
				}
			}
			
			class buttonaction3 extends AbstractAction
			{
				public buttonaction3(String name) 
				{
					putValue(Action.NAME,name);
				}
				public void actionPerformed(ActionEvent e) 
				{
					System.exit(0);
					
				}
			}
			
			Action baction1 = new buttonaction1("Search");
			Action baction2 = new buttonaction2("Play");
			Action baction4 = new buttonaction4("Delete");
			Action baction3 = new buttonaction3("Exit");
			
			// create new button
			button1 = new JButton(baction1);
			button2 = new JButton(baction2);
			button4 = new JButton(baction4);
			button3 = new JButton(baction3);
			
			jp.add(button1);                      // add button
			jp.add(button2);
			jp.add(button4);
			jp.add(button3);
			contentPane.add(jp,BorderLayout.SOUTH);
			
			// create menu bar
			JMenuBar menubar = new JMenuBar();
			setJMenuBar(menubar);
			//add action to menu bar
			JMenu menu = new JMenu("Menu");
			JMenuItem item=new JMenuItem(baction1);
			menu.add(item);
			JMenuItem item2=new JMenuItem(baction2);
			menu.add(item2);
			JMenuItem item4=new JMenuItem(baction4);
			menu.add(item4);
			JMenuItem item3=new JMenuItem(baction3);
			menu.add(item3);
			menubar.add(menu);
			
			// create tool bar
			JToolBar toolBar=new JToolBar();
			toolBar.add(button1);
			toolBar.add(button2);
			toolBar.add(button4);
			toolBar.add(button3);
			contentPane.add(toolBar,BorderLayout.NORTH);
			

			menubar.setVisible(true);
			
			
			pack();
			setVisible(true);	
		}
		  
		
  }
  

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  
  
  
  
  
  
  
  ///
  /// Lit une requete depuis le Terminal, envoie cette requete au serveur,
  /// recupere sa reponse et l'affiche sur le Terminal.
  /// Noter que le programme bloque si le serveur ne repond pas.
  ///
  
  public static void main(String argv[]) {
	String host = DEFAULT_HOST;
    int port = DEFAULT_PORT;
    if (argv.length >=1) host = argv[0];
    if (argv.length >=2) port = Integer.parseInt(argv[1]);
    
    Client client = null;
    
    try {
     client = new Client(host, port);
    }
    catch (Exception e) {
      frame.jta.append("Client: Couldn't connect to "+host+":"+port+"\n");
      System.exit(1);
    }
    
    frame.jta.append("Client connected to "+host+":"+port+"\n");

    // pour lire depuis la console
    int count = 0;
    
    while(true) {
       	if(frame.send) {
    	String request = frame.instruction;
    	String response = client.send(request);
    	frame.jta.append("\nResponse: "+response+"\n");
    	frame.send=false;
    	frame.instruction = null;
    	}
    	count = count+1;
    	if(count>1000) {count=0;}
    }
  }
  
  
  


  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  ///
  /// Initialise la connexion.
  /// Renvoie une exception en cas d'erreur.
  ///
  public Client(String host, int port) throws UnknownHostException, IOException {
    try {
      sock = new java.net.Socket(host, port);
    }
    catch (java.net.UnknownHostException e) {
      System.err.println("Client: Couldn't find host "+host+":"+port);
      throw e;
    }
    catch (java.io.IOException e) {
      System.err.println("Client: Couldn't reach host "+host+":"+port);
      throw e;
    }
    
    try {
      input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
      output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
    }
    catch (java.io.IOException e) {
      System.err.println("Client: Couldn't open input or output streams");
      throw e;
    }
  }
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  
  ///
  /// Envoie une requete au server et retourne sa reponse.
  /// Noter que la methode bloque si le serveur ne repond pas.
  ///
  public String send(String request) {
    // Envoyer la requete au serveur
    try {
      request += "\n";  // ajouter le separateur de lignes
      output.write(request, 0, request.length());
      output.flush();
    }
    catch (java.io.IOException e) {
      System.err.println("Client: Couldn't send message: " + e);
      return null;
    }
    
    // Recuperer le resultat envoye par le serveur
    try {
      return input.readLine();
    }
    catch (java.io.IOException e) {
      System.err.println("Client: Couldn't receive message: " + e);
      return null;
    }
  }
}


