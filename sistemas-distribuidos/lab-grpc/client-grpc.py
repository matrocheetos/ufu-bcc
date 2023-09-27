import grpc
import interface_pb2
import interface_pb2_grpc


def run():
    # NOTE(gRPC Python Team): .close() is possible on a channel and should be
    # used in circumstances in which the with statement does not fit the needs
    # of the code.
    print("Will try to greet world ...")
    with grpc.insecure_channel("localhost:50051") as channel:
        stub = interface_pb2_grpc.GreeterStub(channel)
        response = stub.DigaOlas(interface_pb2.DigaOlasRequest(nomes="teste"))
    print("Greeter client received: " + response.message)


if __name__ == "__main__":
    run()
