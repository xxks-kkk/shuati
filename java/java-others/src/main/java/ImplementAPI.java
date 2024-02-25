import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Stream;

/**
 * Amazon Intern 24' (actual)
 * Cannot pass all the test cases.
 */
@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class ImplementAPI
{
    public List<String> implementAPI(List<String> logs)
    {
        List<String> returns = new ArrayList<>();
        HashMap<String, Map<String, Integer>> user2Password = new HashMap<>();
        for (String request : logs) {
            String[] segments = request.split(" ");
            String username = segments[1];
            String password = "";
            switch (segments[0]) {
                case "register":
                    password = segments[2];
                    if (user2Password.containsKey(username)) {
                        returns.add("Username already exists");
                    }
                    else {
                        Map<String, Integer> status = new HashMap<>();
                        status.put(password, -1);
                        user2Password.put(username, status);
                        returns.add("Registered Successfully");
                    }
                    break;
                case "login":
                    password = segments[2];
                    if (user2Password.containsKey(username)) {
                        Map<String, Integer> status = user2Password.get(username);
                        String storedPwd = "";
                        for (String pwd : status.keySet()) {
                            storedPwd = pwd;
                            if (pwd.equals(password)) {
                                returns.add("Logged In Successfully");
                            }
                            else {
                                returns.add("Login Unsuccessful");
                            }
                        }
                        status.put(storedPwd, 1);
                    }
                    else {
                        returns.add("Login Unsuccessful");
                    }
                    break;
                case "logout":
                    if (user2Password.containsKey(username)) {
                        Map<String, Integer> status = user2Password.get(username);
                        for (String pwd : status.keySet()) {
                            if (status.get(pwd) == 1) {
                                returns.add("Logged Out Successfully");
                            }
                            else {
                                returns.add("Logout Unsuccessful");
                            }
                        }
                    }
                    else {
                        returns.add("Logout Unsuccessful");
                    }
                    break;
            }
        }
        return returns;
    }

    private Stream<Arguments> testDataProvider()
    {
        return Stream.of(
                Arguments.of(List.of("register david david123", "register adam 1Adam1",
                                "login david david123", "login adam 1adam1", "logout david"),
                        List.of("Registered Successfully",
                                "Registered Successfully",
                                "Logged In Successfully",
                                "Login Unsuccessful",
                                "Logged Out Successfully")));
    }

    @ParameterizedTest
    @MethodSource("testDataProvider")
    public void test(List<String> logs, List<String> expected)
    {
        Assertions.assertEquals(expected, implementAPI(logs));
    }
}
