import java.io.*;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

public class DVDCollection {

	// Data fields
	
	/** The current number of DVDs in the array */
	private int numdvds;
	
	/** The array to contain the DVDs */
	private DVD[] dvdArray;
	
	/** The name of the data file that contains dvd data */
	private String sourceName;
	
	/** Boolean flag to indicate whether the DVD collection was
	    modified since it was last saved. */
	private boolean modified;
	
	/**
	 *  Constructs an empty directory as an array
	 *  with an initial capacity of 7. When we try to
	 *  insert into a full array, we will double the size of
	 *  the array first.
	 */
	public DVDCollection() {
		numdvds = 0;
		dvdArray = new DVD[7];
	}
	
	public String toString() {
		// Return a string containing all the DVDs in the
		// order they are stored in the array along with
		// the values for numdvds and the length of the array.
		// See homework instructions for proper format.
		
		//create string to hold numdvds line, dvdArray length, and string for each dvd
		String str = "";
		str += "numdvds = "+ numdvds+ "\n" + "dvdArray.length = " + dvdArray.length + "\n";
		for (int i = 0; i< numdvds; i++) {
			str+= "dvdArray["+ i + "] = " + dvdArray[i].toString() + "min \n";
		}

		return str;	// returns the string
	}

	public void addOrModifyDVD(String title, String rating, String runningTime) {
		// NOTE: Be careful. Running time is a string here
		// since the user might enter non-digits when prompted.
		
		
		// If the array is full and a new DVD needs to be added,
		// double the size of the array first.
		if (numdvds == dvdArray.length) {
			dvdArray = Arrays.copyOf(dvdArray, 2*dvdArray.length);
		}
		
		/*given the title, rating and running time of a DVD, add this DVD to
the collection if the title is not present in the DVD collection or modify the DVD's rating
and running time if the title is present in the collection. Do this operation only if the
rating and running time are valid.


*/
		try {
			int runningtime = Integer.valueOf(runningTime);
			boolean titlePresent=false;
		//	String titleSearch
			
			//first search if dvd is present, if not, add dvd
			
			//dvd is present, so array is modified
			for (int i=0; i < numdvds; i++) {
			//	titleSearch = dvdArray[i].getTitle();
			//	if (titleSearch.compareToIgnoreCase(title)==0) {
				if (dvdArray[i].getTitle().compareToIgnoreCase(title)==0) {
					//if title in array matches the title trying to be added, modify dvd
					titlePresent = true;
					dvdArray[i].setRating(rating);
					dvdArray[i].setRunningTime(runningtime);
				modified = true;
				//dvd array is modified to hold new dvd information	
				}
				
			}
			
			if (titlePresent == false)
			{
				//if the dvd is not present, create a new dvd with the constructor,
				//add it to the dvd array, then sort the array
				DVD newdvd = new DVD(title, rating, runningtime);
					
				dvdArray[numdvds]= newdvd;
				numdvds+=1;
			
			}		

		}
		catch (NumberFormatException e) {
			System.out.println("Invalid runningTime");
		}
	}
	
	public void removeDVD(String title) {
		/*removeDVD - given the title, this method should remove the DVD with this title from
the collection if present. The title must match exactly (in uppercase). If no title matches,
do not change the collection*/
	//	boolean titlePresent=false;
		
		for (int i=0; i<numdvds ; i++) {
			if (dvdArray[i].getTitle().compareTo(title.toUpperCase())==0) {
				//if title in array index matches the title given in uppercase
				System.arraycopy(dvdArray, i+1, dvdArray, i, dvdArray.length - i - 1); 
				//copy the elements from dvdArray to the right of the index where title is 
				//found into the same array at the index
			}	
		}
		numdvds--;
	}
	
	public String getDVDsByRating(String rating) {
/*getDVDsByRating - given the rating, this method should return a string containing all
DVDs that match the given rating in the order that they appear in the collection,
separated by newlines. */
		String dvdMatches = "";
		
		for (int i=0; i<numdvds; i++) {
			if (dvdArray[i].getRating().compareTo(rating)==0) {
				//if the rating of the dvd matches the rating to be found, concat. to string
				//separate by newlines
				dvdMatches += dvdArray[i].toString()+"\n";
			}
		}
		return dvdMatches;	// returns string 
	}

	
	public int getTotalRunningTime() {
		int totalRunningTime=0;
		for (int i=0; i< numdvds ; i++) {
			totalRunningTime += dvdArray[i].getRunningTime();
			//loops through array and retrieves running time, add to counter
		}

		return totalRunningTime;	// returns total running time

	}

	
	public void loadData(String filename) {
/*loadData - given a file name, this method should try to open this file and read the DVD
data contained inside to create an initial alphabetized DVD collection. 
HINT: Read each
set of three values (title, rating, running time) and use the addOrModifyDVD method
above to insert it into the collection. 

If the file cannot be found, start with an empty
array for your collection. 

If the data in the file is corrupted, stop initializing the collection
at the point of corruption.*/

		try {
			BufferedReader reader = new BufferedReader(new FileReader(filename));
			sourceName = filename;
			
			String line = reader.readLine();
			while (line != null) {
				String[] lineSplit = line.split(","); //splits line into dvd, rating, and runtime
				addOrModifyDVD(lineSplit[0], lineSplit[1], lineSplit[2]);
				line = reader.readLine(); //read next line
			}
			reader.close();

			
		}
		catch (FileNotFoundException e) {
			DVDCollection newCollection = new DVDCollection();
		}
		catch (IOException e) {
			System.out.println("Invalid file.\n");
			e.printStackTrace();
		}


		
	}
	
	public void save() {
		/* save - save the DVDs currently in the array into the same file specified during the load
operation, overwriting whatever data was originally there*/
		try {
			FileWriter output = new FileWriter(sourceName, false); //opens file to overwrite
			//output.write(Arrays.toString(dvdArray)); //writes the array to the file
			for (int i=0 ; i<numdvds; i++) {
				
				output.write(dvdArray[i].toString() + "\n");
			}
			
			output.close();	//closes FileWriter

		}
		catch (IOException e) {
			e.printStackTrace();
		}


	}



	// Additional private helper methods go here:
	


	
}
