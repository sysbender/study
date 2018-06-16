package ca.aienglish.qa.ch01;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.support.ui.ExpectedCondition;
import org.openqa.selenium.support.ui.WebDriverWait;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.By;
 
import org.junit.*;
import static org.junit.Assert.*;



public class GooleSearchTest {

	private WebDriver driver;
	
	@Before
	public void setUp() {
		// launch a new chrome instance		
		driver = new ChromeDriver();
		// maximize the window
		driver.manage().window().maximize();
		// navigate to google
		driver.get("http://www.google.com");
	}
	
	
	
	@Test
	public void testGoogleSearch() {
		
		// find text input
		WebElement element = driver.findElement(By.name("q"));
		
		// clear
		element.clear();
		// type
		element.sendKeys("Selenium testing tools cookbook");
		// submit 
		element.submit();
		// wait for loading 
		
		new WebDriverWait(driver,10).until(
				new ExpectedCondition<Boolean>() {

					public Boolean apply(WebDriver d) {
						// TODO Auto-generated method stub
						return d.getTitle().toLowerCase().startsWith("selenium testing tools cookbook");
					} 
					
				}
				
				);
		assertEquals("Selenium testing tools cookbook - Google Search" , driver.getTitle());
	}
	
	
	
	@After
	public void tearDown() throws Exception{
		// close
		driver.close();
	}
}
