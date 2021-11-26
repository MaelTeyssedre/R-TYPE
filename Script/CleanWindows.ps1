Remove-Item build
If ((test-path rtype_server.lnk)) {
    Remove-Item rtype_server.lnk
}
If ((test-path rtype_client.lnk)) {
    Remove-Item rtype_client.lnk
}