package datasource;

import java.sql.Connection; //importer la classe connection de JDBC
import java.sql.DriverManager;
import java.sql.SQLException;


public class SourceDeDonnees {
	
	private Connection cnx;
	
	private String url;
	private String password;
	private String login;
	
	
	public SourceDeDonnees(String url, String password, String login) {
		super();
		this.url = url;
		this.password = password;
		this.login = login;
	}



	public void doConnection() { //charger le driver
	
		try {
			Class.forName("org.mariadb.jdbc.Driver").newInstance();
			
			this.cnx = DriverManager.getConnection(this.url, this.password, this.login);
			
		} catch (InstantiationException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
