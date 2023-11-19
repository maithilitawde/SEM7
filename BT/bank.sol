// SPDX-License-Identifier: MIT
pragma solidity >=0.6.12 <0.9.0;

contract Bank{

  mapping(address=>uint)public user_account;
  mapping(address=>bool)public user_exists;

  function createAccount() public payable returns(string memory)
  {
    require(user_exists[msg.sender] == false , "Account Already Created");
    user_account[msg.sender] = msg.value;
    user_exists[msg.sender] = true;
    return "Account Created Successfully!";
  }

  function deposite(uint amount) public payable returns(string memory)
  {
    require(user_exists[msg.sender] == true , "Account does not exist");
    require(amount>0 , "Amount should be greater than 0");
    user_account[msg.sender] += amount;
    return "Amount Deposited Successfully";
  }

  function withdraw(uint amount) public payable returns(string memory)
  {
    require(user_exists[msg.sender] == true , "Account does not exist");
    require(amount>0 , "Amount should be greater than 0");
    require(user_account[msg.sender] >= amount , "Amount greater than the balance");
    user_account[msg.sender] -= amount;
    return "Amount withdrawn successfully"; 
  }
  
  function checkbalance() public view returns(uint)
  {
    return user_account[msg.sender];
  }

  function checkuser() public view returns(bool)
  {
    return user_exists[msg.sender];
  }

}
