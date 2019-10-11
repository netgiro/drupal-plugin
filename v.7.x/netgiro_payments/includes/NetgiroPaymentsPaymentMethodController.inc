<?php

/**
 * Contains NetgiroPaymentPPSPaymentMethodController.
 */

/**
 * A Netgiro Payments Standard payment method.
 */
class NetgiroPaymentsPaymentMethodController extends PaymentMethodController {

  /**
   * The production server URL.
   */
  const SERVER_URL = 'https://securepay.netgiro.is/v1/';

  /**
   * The TEST server URL.
   */
  const TEST_SERVER_URL = 'http://test.netgiro.is/securepay';

  public $controller_data_defaults = array(
    'server' => self::TEST_SERVER_URL,
    '14_days' => TRUE,
    'partial_payments' => TRUE,
    'partial_payments_without_interest' => FALSE,
    'application_id' => '881E674F-7891-4C20-AFD8-56FE2624C4B5',
    'secret_key' => 'YCFd6hiA8lUjZejVcIf/LhRXO4wTDxY0JhOXvQZwnMSiNynSxmNIMjMf1HHwdV6cMN48NX3ZipA9q9hLPb9C1ZIzMH5dvELPAHceiu7LbZzmIAGeOf/OUaDrk2Zq2dbGacIAzU6yyk4KmOXRaSLi8KW8t3krdQSX7Ecm8Qunc/A=',
  );

  public $payment_method_configuration_form_elements_callback = 'netgiro_payments_payment_method_configuration_form_elements';

  function __construct() {
    $currency_codes = array('ISK');
    $this->currencies = array_fill_keys($currency_codes, array());
    $this->title = 'Netgiro Payments';
  }

  /**
   * Implements PaymentMethodController::validate().
   */
  function validate(Payment $payment, PaymentMethod $payment_method, $strict) {
  }

  /**
   * Implements PaymentMethodController::execute().
   */
  function execute(Payment $payment) {
    entity_save('payment', $payment);
    $_SESSION['netgiro_payments_pid'] = $payment->pid;
    drupal_goto('netgiro_payments/redirect/' . $payment->pid);
  }

}