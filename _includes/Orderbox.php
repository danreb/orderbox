<?php

/**
 * Orderbox Class wrapper
 *
 * @author Adolfo G. Nasol
 */
require("OrderboxConfiguration.php");

class Orderbox {
    /*
     * Configuration (credentials, host,...)
     */
    private $configuration;
    /**
     * Url of the resource to call
     */
    private $url;
    /**
     * Debug or Test 
     */
    private $debugMode;
    /**
     * Service Name
     */
    private $serviceName;
    /**
     * Construct the class, build the API url and init options
     * @param
     */
    public function __construct($configuration = false){
  if(!$configuration) $configuration = new OrderboxConfiguration();
  $this->configuration = $configuration;
        $this->debugMode = $this->configuration->get('debugMode');
        if ($this->debugMode) {
            $this->url = $this->configuration->get('apiTestUrl');
        } else {
            $this->url = $this->configuration->get('apiUrl'); 
        }
     }
     
     /*
      * Build the base URL to check available  domain names.
      * 
      */
    public function domainsAvailabilityCheck() {
        $this->serviceName = $this->url . 'domains/available.' . $this->configuration->get('returnType');
        return $this->serviceName;
    }
    
      /*
      * Build the base URL to check available IDN domain names.
      * 
      */
    public function domainsAvailabilityCheckIdn() {
        $this->serviceName = $this->url . 'domains/idn-available.' . $this->configuration->get('returnType');
        return $this->serviceName;
    }
    
     /*
      * Build URL for Domain name Suggestion
      * 
      */
    public function domainsSuggestion() {
        $this->serviceName = $this->url . 'domains/suggest-names.' . $this->configuration->get('returnType');
        return $this->serviceName;
    }
      /*
      * Build Base URL for Domain name Registration
      * 
      */
    public function registerDomains() {
        $this->serviceName = $this->url . 'domains/register.' . $this->configuration->get('returnType');
        return $this->serviceName;
    }
}
