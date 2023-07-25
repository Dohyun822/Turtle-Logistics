package class2.a204.entity;

import com.fasterxml.jackson.annotation.JsonProperty;
import com.sun.istack.NotNull;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.persistence.*;
import java.time.LocalDateTime;

@Entity
@Data
@NoArgsConstructor
@Table(name = "log")
public class Log {
    @JsonProperty("log_num")
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "log_num")
    @NotNull
    private Integer logNum;

    @JsonProperty("error_date")
    @Column(name = "error_date", insertable = false)
    @NotNull
    private LocalDateTime errorDate;

    @JsonProperty("error_message")
    @Column(name = "error_message")
    private String errorMessage;

    @ManyToOne
    @JoinColumn(name = "machine_id")
    @NotNull
    private Machine machine;

    public Log(Machine machine2, String logForBrokenMachine) {
    }

}