import java.util.ArrayList;
import java.util.List;

// Employee info
class Employee {
    // It's the unique id of each node;
    // unique id of this employee
    public int id;
    // the importance value of this employee
    public int importance;
    // the id of direct subordinates
    public List<Integer> subordinates;
};


// Runtime: 31 ms
public class Solution690 {
    public int getImportance(List<Employee> employees, int id) {
        List<Integer> subordinates = null;
        int importance = 0;
        for (Employee e : employees) {
            if (e.id == id) {
                subordinates = e.subordinates;
                importance += e.importance;
                break;
            }
        }
        if (subordinates != null) {
            for (Integer sub : subordinates) {
                importance += getImportance(employees, sub);
            }
        }
        return importance;
    }

    public static void main(String[] args) {
        Employee a = new Employee();
        a.id = 1;
        a.importance = 5;

        Employee b = new Employee();
        b.id = 2;
        b.importance = 3;

        Employee c = new Employee();
        c.id = 3;
        c.importance = 3;

        a.subordinates = new ArrayList<>();
        a.subordinates.add(2);
        a.subordinates.add(3);

        List<Employee> l = new ArrayList<>();
        l.add(a);
        l.add(b);
        l.add(c);
        System.out.println(new Solution690().getImportance(l, 1));
    }
}
