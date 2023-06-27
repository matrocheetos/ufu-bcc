<?php

class RequestResponse
{
  public $success;
  public $detail;

  function __construct($success, $detail)
  {
    $this->success = $success;
    $this->detail = $detail;
  }
}

session_start();

if (isset($_SESSION['loggedIn'])) {
  $response = new RequestResponse(true, './anunciante/anunciante.php');
  header('Content-type: application/json');
  echo json_encode($response);
  exit();
} else {
  $response = new RequestResponse(false, '');
  header('Content-type: application/json');
  echo json_encode($response);
  exit();
}
