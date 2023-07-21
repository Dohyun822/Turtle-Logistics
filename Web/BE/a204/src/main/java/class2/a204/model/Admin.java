package class2.a204.model;

import com.sun.istack.NotNull;

import javax.persistence.*;

@Entity
@Table(name = "admin")
public class Admin {
    @Id
    @Column(name = "admin_id")
    private String id;

    @NotNull
    private String password;

    @Column(name = "phone_number")
    private String phoneNumber;

    //기본생성자
    public Admin() {
    }

    //getters and setters
    public String getId() {
        return id;
    }

    public String getPassword() {
        return password;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setId(String id) {
        this.id = id;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }
}