package com.example.demo;

import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

@RestController
public class AddressController {

    private List<Address> addresses = new ArrayList<>(
        Arrays.asList(
            new Address("34800100", "Floriano Peixoto", "Centro", "Uberlândia"),
            new Address("34800100", "Tiradentes", "Fundinho", "Uberlândia"),
            new Address("34800100", "Lions Clube", "Osvaldo Rezende", "Uberlândia")
        )
    );

    @GetMapping("/address")
    public List<Address> getAddresses() {
        return this.addresses;
    }

    @GetMapping("/address/{cep}")
    public ResponseEntity<Address> getAddress(@PathVariable String cep) {
        for (Address address : this.addresses)
            if (address.getCep().equals(cep))
                return ResponseEntity.ok(address);
        return ResponseEntity.notFound().build();
    }

    @PostMapping("/address")
    public void addAddress(@RequestBody Address address) {
        this.addresses.add(address);
    }

    @DeleteMapping("/address/{cep}")
    public void deleteAddress(@PathVariable String cep) {
        for (Address address : this.addresses)
            if (address.getCep().equals(cep))
                addresses.remove(address);
    }

    @GetMapping("/hello")
    public String helloWorld() {
        return "Hello World!";
    }
}
