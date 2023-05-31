package com.example.demo;

import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;

import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

@RestController
public class CustomerController {
    private List<Customer> customers = new ArrayList<>(
            Arrays.asList(
                    new Customer("12345", "victor", "3499998888"),
                    new Customer("11234", "victor2", "3499998888"),
                    new Customer("11123", "victor3", "3499998888")
            )
    );
    @GetMapping("/hello")
    public String helloWorld() {
        return "Hello World";
    }

    @GetMapping("/customer")
    public List<Customer> getCustomers() {
        return this.customers;
    }

    @GetMapping("/customer/{cpf}")
    public ResponseEntity<Customer> getCustomer(@PathVariable String cpf){
        for (Customer c : this.customers)
            if (c.getCpf().equals(cpf))
                return ResponseEntity.ok(c);
        return ResponseEntity.notFound().build();
    }
}
