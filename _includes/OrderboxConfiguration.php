<?php

/**
 * Ordebox Domains Configuration class
 *
 * @author Adolfo G. Nasol
 */
class OrderboxConfiguration {

  /*
   * Orderbox HTTP API URL
   */
  private $apiUrl;
  /*
   * Orderbox API Test URL
   */
  private $apiTestUrl;
  /*
   * Foundation API Servlet URL
   */
  private $servletUrl;
  /*
   * Orderbox Reseller ID
   */
  private $authUserId;
  /*
   * Ordebox Reseller Password
   */
  private $authPassword;
  /**
   * Type of the return data(json, xml)
   * Defult to json
   */
  private $returnType;
  /**
   *  Debug Mode, False by default
   *  Use the test URL if true
   */
  private $debugMode;  
  /*
   * Domain name to check
   */
  private $domainName;
  /*
   * TLDs for which the domain name 
   * availability needs to be checked.
   */
  private $tlds;
  /*
   * suggest alternative if domain is taken
   */
  private $suggestAlternative;
  
  /**
   * Construct the class and initiliaze with default values
   * @param
   */
  public function __construct(){
    $this->apiUrl               = 'https://httpapi.com/api/';
    $this->apiTestUrl           = 'https://test.httpapi.com/api/'; 
    $this->servletUrl           = 'https://www.foundationapi.com/servlet/AuthenticationServlet';
    $this->authUserId           = '';
    $this->authPassword         = '';
    $this->returnType           = 'json';
    $this->debugMode            = FALSE;
    $this->domainName           = '';
    $this->tlds                 = 'com';
    $this->suggestAlternative   = TRUE;
  }
  
  public function get($var){
    return $this->$var;
  }
  
  public function set($var,$val){
    $this->$var = $val;
    return $this;
  }
  
}
