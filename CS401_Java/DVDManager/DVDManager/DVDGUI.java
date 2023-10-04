import javax.swing.*;

/**
 *  This class is an implementation of DVDUserInterface
 *  that uses JOptionPane to display the menu of command choices. 
 */

public class DVDGUI implements DVDUserInterface {
	 
	 private DVDCollection dvdlist;
	
	 
	 public static void buildGUI() {
		 JFrame frame = new JFrame("DVDGUI"); 
		 frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		 JPanel listPanel = new JPanel();
		 frame.add(listPanel);
	 
	 
	 
	 
	 
	 }
	 
	 public DVDGUI(DVDCollection dl)
	 {
		 dvdlist = dl;
	 }
	 
	 
	 public void processCommands() {
		 
	 }
	 
	 
	 public static void main(String args[]) {
		 
		 buildGUI();
		 
	 }
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	/* public void processCommands()
	 {
		 String[] commands = {"Add/Modify DVD",
				 	"Remove DVD",
				 	"Get DVDs By Rating",
				 	"Get Total Running Time",
				 	"Exit and Save"};
		 
		 int choice;
		 
		 do {
			 choice = JOptionPane.showOptionDialog(frame,
					 "Select a command", 
					 "DVD Collection", 
					 JOptionPane.YES_NO_CANCEL_OPTION, 
					 JOptionPane.QUESTION_MESSAGE, 
					 null, 
					 commands,
					 commands[commands.length - 1]);
		 
			 switch (choice) {
			 	case 0: doAddOrModifyDVD(); break;
			 	case 1: doRemoveDVD(); break;
			 	case 2: doGetDVDsByRating(); break;
			 	case 3: doGetTotalRunningTime(); break;
			 	case 4: doSave(); break;
			 	default:  // do nothing
			 }
			 
		 } while (choice != commands.length-1);
		 System.exit(0);
	 }

	private void doAddOrModifyDVD() {

		// Request the title
		String title = JOptionPane.showInputDialog(frame, "Enter title");
		if (title == null) {
			return;		// dialog was cancelled
		}
		title = title.toUpperCase();
		
		// Request the rating
		String rating = JOptionPane.showInputDialog(frame, "Enter rating for " + title);
		if (rating == null) {
			return;		// dialog was cancelled
		}
		rating = rating.toUpperCase();
		
		// Request the running time
		String time = JOptionPane.showInputDialog(frame, "Enter running time for " + title);
		if (time == null) {
		}
		
                // Add or modify the DVD (assuming the rating and time are valid
                dvdlist.addOrModifyDVD(title, rating, time);
                
          /*      // Display current collection to the console for debugging
                System.out.println("Adding/Modifying: " + title + "," + rating + "," + time);
                System.out.println(dvdlist);		*/
               // JOptionPane.showInternalMessageDialog(null, "Adding/Modifying: " + title + "," + rating + "," + time);
               // JOptionPane.showInternalMessageDialog(null, dvdlist);
	/*}
	
	private void doRemoveDVD() {

		// Request the title
		String title = JOptionPane.showInputDialog(frame, "Enter title");
		if (title == null) {
			return;		// dialog was cancelled
		}
		title = title.toUpperCase();
		
                // Remove the matching DVD if found
                dvdlist.removeDVD(title);
                
       /*         // Display current collection to the console for debugging
                System.out.println("Removing: " + title);
                System.out.println(dvdlist);
        */
	/*}
	
	private void doGetDVDsByRating() {

		// Request the rating
		String rating = JOptionPane.showInputDialog(frame, "Enter rating");
		if (rating == null) {
			return;		// dialog was cancelled
		}
		rating = rating.toUpperCase();
		
        String results = dvdlist.getDVDsByRating(rating);
        JOptionPane.showMessageDialog(frame, results);   
                
         /*       System.out.println("DVDs with rating " + rating);
                System.out.println(results);		*/

	/*}

        private void doGetTotalRunningTime() {
                 
                int total = dvdlist.getTotalRunningTime();
                JOptionPane.showMessageDialog(frame, "Total Running Time of DVDs: " + total + " minutes.");
                
                
         /*       System.out.println("Total Running Time of DVDs: ");
                System.out.println(total);		*/
                
    /*    }

	private void doSave() {
		
		dvdlist.save();
		
	}*/
		
}
