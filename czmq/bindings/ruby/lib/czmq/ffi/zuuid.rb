################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################

module CZMQ
  module FFI

    # UUID support class
    # @note This class is 100% generated using zproject.
    class Zuuid
      # Raised when one tries to use an instance of {Zuuid} after
      # the internal pointer to the native object has been nullified.
      class DestroyedError < RuntimeError; end

      # Boilerplate for self pointer, initializer, and finalizer
      class << self
        alias :__new :new
      end
      # Attaches the pointer _ptr_ to this instance and defines a finalizer for
      # it if necessary.
      # @param ptr [::FFI::Pointer]
      # @param finalize [Boolean]
      def initialize(ptr, finalize = true)
        @ptr = ptr
        if @ptr.null?
          @ptr = nil # Remove null pointers so we don't have to test for them.
        elsif finalize
          @finalizer = self.class.create_finalizer_for @ptr
          ObjectSpace.define_finalizer self, @finalizer
        end
      end
      # @param ptr [::FFI::Pointer]
      # @return [Proc]
      def self.create_finalizer_for(ptr)
        Proc.new do
          ptr_ptr = ::FFI::MemoryPointer.new :pointer
          ptr_ptr.write_pointer ptr
          ::CZMQ::FFI.zuuid_destroy ptr_ptr
        end
      end
      # @return [Boolean]
      def null?
        !@ptr or @ptr.null?
      end
      # Return internal pointer
      # @return [::FFI::Pointer]
      def __ptr
        raise DestroyedError unless @ptr
        @ptr
      end
      # So external Libraries can just pass the Object to a FFI function which expects a :pointer
      alias_method :to_ptr, :__ptr
      # Nullify internal pointer and return pointer pointer.
      # @note This detaches the current instance from the native object
      #   and thus makes it unusable.
      # @return [::FFI::MemoryPointer] the pointer pointing to a pointer
      #   pointing to the native object
      def __ptr_give_ref
        raise DestroyedError unless @ptr
        ptr_ptr = ::FFI::MemoryPointer.new :pointer
        ptr_ptr.write_pointer @ptr
        __undef_finalizer if @finalizer
        @ptr = nil
        ptr_ptr
      end
      # Undefines the finalizer for this object.
      # @note Only use this if you need to and can guarantee that the native
      #   object will be freed by other means.
      # @return [void]
      def __undef_finalizer
        ObjectSpace.undefine_finalizer self
        @finalizer = nil
      end

      # Create a new UUID object.
      # @return [CZMQ::Zuuid]
      def self.new()
        ptr = ::CZMQ::FFI.zuuid_new()
        __new ptr
      end

      # Create UUID object from supplied ZUUID_LEN-octet value.
      # @param source [::FFI::Pointer, #to_ptr]
      # @return [CZMQ::Zuuid]
      def self.new_from(source)
        ptr = ::CZMQ::FFI.zuuid_new_from(source)
        __new ptr
      end

      # Destroy a specified UUID object.
      #
      # @return [void]
      def destroy()
        return unless @ptr
        self_p = __ptr_give_ref
        result = ::CZMQ::FFI.zuuid_destroy(self_p)
        result
      end

      # Set UUID to new supplied ZUUID_LEN-octet value.
      #
      # @param source [::FFI::Pointer, #to_ptr]
      # @return [void]
      def set(source)
        raise DestroyedError unless @ptr
        self_p = @ptr
        result = ::CZMQ::FFI.zuuid_set(self_p, source)
        result
      end

      # Set UUID to new supplied string value skipping '-' and '{' '}'
      # optional delimiters. Return 0 if OK, else returns -1.         
      #
      # @param source [String, #to_s, nil]
      # @return [Integer]
      def set_str(source)
        raise DestroyedError unless @ptr
        self_p = @ptr
        result = ::CZMQ::FFI.zuuid_set_str(self_p, source)
        result
      end

      # Return UUID binary data.
      #
      # @return [::FFI::Pointer]
      def data()
        raise DestroyedError unless @ptr
        self_p = @ptr
        result = ::CZMQ::FFI.zuuid_data(self_p)
        result
      end

      # Return UUID binary size
      #
      # @return [Integer]
      def size()
        raise DestroyedError unless @ptr
        self_p = @ptr
        result = ::CZMQ::FFI.zuuid_size(self_p)
        result
      end

      # Returns UUID as string
      #
      # @return [String]
      def str()
        raise DestroyedError unless @ptr
        self_p = @ptr
        result = ::CZMQ::FFI.zuuid_str(self_p)
        result
      end

      # Return UUID in the canonical string format: 8-4-4-4-12, in lower
      # case. Caller does not modify or free returned value. See        
      # http://en.wikipedia.org/wiki/Universally_unique_identifier      
      #
      # @return [String]
      def str_canonical()
        raise DestroyedError unless @ptr
        self_p = @ptr
        result = ::CZMQ::FFI.zuuid_str_canonical(self_p)
        result
      end

      # Store UUID blob in target array
      #
      # @param target [::FFI::Pointer, #to_ptr]
      # @return [void]
      def export(target)
        raise DestroyedError unless @ptr
        self_p = @ptr
        result = ::CZMQ::FFI.zuuid_export(self_p, target)
        result
      end

      # Check if UUID is same as supplied value
      #
      # @param compare [::FFI::Pointer, #to_ptr]
      # @return [Boolean]
      def eq(compare)
        raise DestroyedError unless @ptr
        self_p = @ptr
        result = ::CZMQ::FFI.zuuid_eq(self_p, compare)
        result
      end

      # Check if UUID is different from supplied value
      #
      # @param compare [::FFI::Pointer, #to_ptr]
      # @return [Boolean]
      def neq(compare)
        raise DestroyedError unless @ptr
        self_p = @ptr
        result = ::CZMQ::FFI.zuuid_neq(self_p, compare)
        result
      end

      # Make copy of UUID object; if uuid is null, or memory was exhausted,
      # returns null.                                                      
      #
      # @return [Zuuid]
      def dup()
        raise DestroyedError unless @ptr
        self_p = @ptr
        result = ::CZMQ::FFI.zuuid_dup(self_p)
        result = Zuuid.__new result, false
        result
      end

      # Self test of this class.
      #
      # @param verbose [Boolean]
      # @return [void]
      def self.test(verbose)
        verbose = !(0==verbose||!verbose) # boolean
        result = ::CZMQ::FFI.zuuid_test(verbose)
        result
      end
    end
  end
end

################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
