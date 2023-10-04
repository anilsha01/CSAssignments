// The Stock program is following the MVC design template and this is our controller object.
// The main functionality for buying and selling the stocks are in this controller object.
// This is the ONLY file you may edit

import java.util.LinkedList;
import java.util.Scanner;

public class Controller {
	
	public Controller() {
		LinkedList<Stock> stockList = new LinkedList<Stock>();
		//LinkedList<Stock> amazList = new LinkedList<Stock>();
		Scanner input = new Scanner(System.in);
		
		do {
			
			System.out.print("Enter 1 to buy, 2 to sell, or 3 to quit: ");
			int stockSelect = input.nextInt();
			if(stockSelect == 3)
				break;
			
			System.out.print("How many shares: ");
			int numShares = input.nextInt();		
			
			System.out.print("At what price: ");
			double price = input.nextDouble();
			
			
			System.out.print("Enter the name of the stock: ");
			String stockName = input.next();		
			if (stockSelect == 1) { //if user wants to buy a stock
				Controller.buyStock(stockList, stockName, numShares, price);
			}
			
			else { //user wants to sell a stock
				System.out.print("Enter 1 for LIFO accounting or 2 for FIFO Accounting: ");
				int sellChoice = input.nextInt();
				if (sellChoice == 1)
					Controller.sellLIFO(stockList, stockName, numShares, price);
				else
					Controller.sellFIFO(stockList, stockName, numShares, price);
			}
			
			
		} while(true);
		input.close();
	}
			
	public static void buyStock(LinkedList<Stock> list, String name, int quantity, double price) {
		Stock temp = new Stock(name,quantity,price);
		list.push(temp);
		System.out.printf("You bought %d shares of %s stock at $%.2f per share %n", quantity, name, price);
	}
	
	public static void sellLIFO(LinkedList<Stock> list, String stockName, int numToSell, double priceOfStock) {
	    // You need to write the code to sell the stock using the LIFO method (Stack)
	    // You also need to calculate the profit/loss on the sale
		Stock lifoStock = list.removeFirst();
		String name = lifoStock.getName();	//use for debugging
		double price = lifoStock.getPrice();  
		
		int quantity = lifoStock.getQuantity();
		double total = 0; // this variable will store the total after the sale
	    double profit = 0; // the price paid minus the sale price, negative # means a loss
	    
	    
		if (numToSell > quantity || stockName != name) { //removes runtime exception, adds stock back to list
			System.out.println("You are trying to sell stock than you don't own! Please try again. ");
			list.addFirst(lifoStock);
		}
		else {
			total = numToSell * priceOfStock;		//profit is the selling price minus the cost price
	    	profit = total - (numToSell * price); 
		    if (numToSell == quantity) { 
		    	
		    	//leave the deleted the stock from list
		    	
		    }
		    else {	//update the stock quantity and add back to list
		  
		    	int updatedQuantity = quantity - numToSell;
		    	lifoStock.setQuantity(updatedQuantity);
		    	list.addFirst(lifoStock);
		    	
		    }
		     
			System.out.printf("You sold %d shares of %s stock at %.2f per share %n", numToSell, list.element().getName(), total/numToSell);
		    System.out.printf("You made $%.2f on the sale %n", profit);
		}
	}
	
	public static void sellFIFO(LinkedList<Stock> list, String stockName, int numToSell, double priceOfStock) {
	    // You need to write the code to sell the stock using the FIFO method (Queue)
	    // You also need to calculate the profit/loss on the sale
		Stock fifoStock = list.removeLast();
		String name = fifoStock.getName();	//use for debugging
		double price = fifoStock.getPrice();  
		
		int quantity = fifoStock.getQuantity();
		double total = 0; // this variable will store the total after the sale
	    double profit = 0; // the price paid minus the sale price, negative # means a loss
	    
	    
		if (numToSell > quantity || stockName != name) { //removes runtime exception, adds stock back to list
			System.out.println("You are trying to sell stock than you don't own! Please try again. ");
			list.addLast(fifoStock);
		}
		else {
			total = numToSell * priceOfStock;		//profit is the selling price minus the cost price
	    	profit = total - (numToSell * price); 
		    if (numToSell == quantity) { 
		    	
		    	//leave the deleted the stock from list
		    	
		    }
		    else {	//update the stock quantity and add back to list
		  
		    	int updatedQuantity = quantity - numToSell;
		    	fifoStock.setQuantity(updatedQuantity);
		    	list.addLast(fifoStock);
		    	
		    }
		     
			System.out.printf("You sold %d shares of %s stock at %.2f per share %n", numToSell, list.element().getName(), total/numToSell);
		    System.out.printf("You made $%.2f on the sale %n", profit);
		}
	}
}
