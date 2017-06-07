String NfcScan() {
  if (nfc.tagPresent()) {
    NfcTag tag = nfc.read();
    String scannedUID = "";
    scannedUID = tag.getUidString();
    return scannedUID;
  }
  else {
    return "";
  }
}
