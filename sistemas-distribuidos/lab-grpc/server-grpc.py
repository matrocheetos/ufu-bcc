import grpc
import interface_pb2
import interface_pb2_grpc


class Greeter(interface_pb2_grpc.GreeterServicer):
    # def SayHello(self, request, context):
    #     return interface_pb2.HelloReply(message="Hello, %s!" % request.name)
    def DigaOla(self, request, context):
        return interface_pb2.DigaOlasReply(message=f"Olá  {request.nomes}")

def serve():
    port = "50051"
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    interface_pb2_grpc.add_GreeterServicer_to_server(Greeter(), server)
    server.add_insecure_port("[::]:" + port)
    server.start()
    print("Server started, listening on " + port)
    server.wait_for_termination()


if __name__ == "__main__":
    serve()
